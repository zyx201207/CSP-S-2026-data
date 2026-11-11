#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool f1 = true;
	bool f2 = true;
	bool f3 = true;

	//两张车票对应的座位是否在同一节车厢
	if(c1 == c2){
		cout << 1;
	}else{
		cout << 0;
		f1 = false;
	}
	
	//两张车票对应的座位是否在同一节车厢的同一排
	if(f1 == false){
		cout << 0;
		f2 = false;
	}else{
		for(int i=0;i<2;i++){
			if(s1[i] != s2[i]){
				f2 = false;
			}
		}
		if(f2 == true){
			cout << 1;
		}else{
			cout << false;
		}
	}
	

	
	//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
	if(f1 == false || f2 == false){
		cout << 0;
		f3 = false;
	}else{
		if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')){
			cout << 1;
		}else{
			cout << 0;
			f3 = false;
		}
	}
	
	//两张车票对应的座位是否相邻
	if(f1 == false || f2 == false || f3 == false){
		cout << 0;
	}else{
		if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'F' && s2[2] == 'D')){
			cout << 1;
		}else{
			cout << 0;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
