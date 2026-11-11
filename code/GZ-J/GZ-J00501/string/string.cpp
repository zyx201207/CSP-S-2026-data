//GZ-J00501 ¸ß´ï 
#include<bits/stdc++.h>
using namespace std;
int n ,cnt;
int ans=0 ;
int q;
string s1 ,s2,s3;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n ;
	while(n--){
	string s;
	cin >> q>> s;
	for(int i = 0 ; i<q ; i++){
		s1=s1+s;
	}
}
	for(int i =s1.size()-1;i>=0;i--){
		s2[cnt]=s1[i];
		cnt++;
	}
	int t= 0 ;
	for(int i = 0 ; i<cnt ; i++){
	if(s2[i]==s1[i]){
		t++;
	}
}
	if(t==cnt){
		cout << 0 ;
		return 0 ;
	}
	for(int i = 0 ; i<cnt ; i++){
		for(int j = cnt-1 ; j>=0 ; j--){
				if(s1[i]!=s1[j]&&i!=cnt/2&&j!=cnt/2){
					s1[j]=s1[i];
					ans++ ;	
			}
	}
	
	
}
	cout << ans ;
	return 0 ;
}
