#include<bits/stdc++.h>
using namespace std;
int a,b;
char x[10086],y[10086];
int l,cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>x[i];
	}if(x[3]=='D' or x[3]=='F')l++;
	cin>>b;
	for(int i=1;i<=3;i++){
		cin>>y[i];
	}if(y[3]=='D' or y[3]=='F')l++;
	if(a==b){
		cout<<1;
		cnt++;
		if(x[1]==y[1] and x[2]==y[2]){
			cout<<1;
			cnt++;
			if(l!=1){
				cout<<1;
				cnt++;
				if(x[3]+1 ==y[3] or y[3]+1==x[3]){
					cout<<1;
					cnt++;
				}
			}
		}
	}for(int i=1;i<=4-cnt;i++){
		cout<<0;
	}
	return 0;
} 
