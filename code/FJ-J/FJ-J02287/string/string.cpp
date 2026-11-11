#include<bits/stdc++.h>
using namespace std;
void mas(){
	char ans[2005]={};
	int n,cnt=1,sum=0;
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int i=cnt;i<cnt+a;i++){
			ans[i]=c;
		}cnt=a+cnt;
	}cnt-=1;
//	for(int i=1;i<=cnt;i++){
//		cout<<ans[i];
//	}cout<<"\n"<<cnt;
	for(int i=1;i<=cnt/2;i++){
		if(ans[i]!=ans[cnt-i+1])sum++;
	}cout<<sum;
	}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		mas();	
	}
	return 0;	
}
