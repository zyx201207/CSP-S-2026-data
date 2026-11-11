#include<bits/stdc++.h>
using namespace std;
long long a1,b1;
string a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1 == b1){
		cout<<1;
		if(a2[0] == b2[0]&&a2[1] == b2[1]){
			cout<<1;
			long long ans = 0;
			long long ans1 = a2[2]-'A',ans2 = b2[2]-'A';
			for(long long i = 0;i<3;i++){
				if(ans1 == i||ans2 == i){
					ans++;
				}
			}
			if(ans == 0||ans == 2){
				cout<<1; 
				if(abs(ans1-ans2) == 1||(ans1 == 3&&ans2 == 5)||(ans1 == 5&&ans2 == 3)){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0; 
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	
	return 0;
}

