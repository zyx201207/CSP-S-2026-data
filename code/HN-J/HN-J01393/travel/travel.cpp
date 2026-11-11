#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
long long cnt = 0;

void work(){
	if(c1 == c2){
		cnt += 1000;
	}
	
	while(cnt == 1000){
		int i = 1;
		if(s1 == "0",i && s2 == "0",i){
				i++;
				cnt += 100;
				break;
			}
	}
		
	while(cnt == 1100){
		int i = 1;
		if(s1 == "0",i,"A" || s1 == "0",i,"B" || s1 == "0",i,"C" || s2 == "0",i,"A" || s2 == "0",i,"B" || s2 == "0",i,"C" || s1 == "0",i,"D" || s1 == "0",i,"F" || s2 == "0",i,"D" || s2 == "0",i,"F"){
			i++;
			cnt += 10;
			break;
		}
	}
	
	while(cnt == 1110){
		int i = 1;
			if(s1 == "0",i,"A" && s2 == "0",i,"B" || s1 == "0",i,"B" && s2 == "0",i,"A" || s1 == "0",i,"B" && s2 == "0",i,"C" || s1 == "0",i,"C" && s2 == "0",i,"B"){
				i++;
				if(s1 == "0",i,"D" && s2 == "0",i,"F" || s1 == "0",i,"F" && s2 == "0",i,"D"){
					i++;
					cnt += 1;
					break;
				}
			}
	}
	cout << cnt;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	work();
	return 0;
}
