#include <bits/stdc++.h>
using namespace std ;

struct point {
	long long num ;
	char word ;
};

int main() {
	
	freopen ("string.in","r",stdin) ;
	freopen ("string.out","w",stdout) ;
	
	long long n ;
	cin >> n ;
	
	vector <point> strIng ;
	long long wordS_num = 0 ; 
	
	while (n--){
		point temp ;
		cin >> temp.num >> temp.word ;
		wordS_num += temp.num ; 
		if (strIng.size()){
			if (strIng.back().word==temp.word){
				strIng [strIng.size()-1].num += temp.num ;
				continue ;
			}
		}
		strIng.push_back(temp) ;
	}
	
	if (strIng.size()==1){
		cout << 0 ;
		return 0 ;
	}
	
	vector <point> string_left ;
	vector <point> string_right;
	
	for (long long i = 0 , temp = wordS_num/2 ; i <strIng.size(),temp>0;i++){
		if (strIng[i].num<=temp){
			temp -= strIng[i].num ;
			string_left.push_back(strIng[i]);
		}else{
			string_left.push_back({temp,strIng[i].word});
			temp = 0 ;
		}
	}
	
	for (long long i = strIng.size()-1 , temp = wordS_num/2 ; i >= 0 ,temp>0;i--){
		if (strIng[i].num<=temp){
			temp -= strIng[i].num ;
			string_right.push_back(strIng[i]);
		}else{
			string_right.push_back({temp,strIng[i].word});
			temp = 0 ;
		}
	}
	long long ans = 0 ;
	for (long long i = 0 , Lp=0,Rp=0; i < wordS_num/2 ; ){
		if (string_left[Lp].word==string_right[Rp].word){
			if (string_left[Lp].num==string_right[Rp].num){
				i+=string_left[Lp].num ;
				string_left[Lp].num -= 0 ;
				string_right[Rp].num -= 0 ;
				Lp++;
				Rp++;
			}else if (string_left[Lp].num<string_right[Rp].num){
				i+=string_left[Lp].num ;
				string_right[Rp].num -= string_left[Lp].num ;
				Lp++;
			}else{
				i+=string_right[Lp].num ;
				string_left[Lp].num -= string_right[Rp].num ;
				Rp++;
			}
		}else{
			if (string_left[Lp].num==string_right[Rp].num){
				i+=string_left[Lp].num ;
				ans+=string_left[Lp].num ;
				string_left[Lp].num -= 0 ;
				string_right[Rp].num -= 0 ;
				Lp++;
				Rp++;
			}else if (string_left[Lp].num<string_right[Rp].num){
				i+=string_left[Lp].num ;
				ans+=string_left[Lp].num ;
				string_right[Rp].num -= string_left[Lp].num ;
				Lp++;
			}else{
				i+=string_right[Lp].num ;
				ans+=string_right[Lp].num ;
				string_left[Lp].num -= string_right[Rp].num ;
				Rp++;
			}
		}
	}
	
	cout << ans ;
	
	return 0 ;
}
