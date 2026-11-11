#include<bits/stdc++.h>
using namespace std;
char c[200001];
char d[200001];
int n;
int a;
int ans=0;
int aans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a;
			cin>>c[i];
			aans+=a;
		}
		int j=1;
		for(int i=aans;i>=1;i--){
			if(c[i]!=c[j]&&(i+j)<aans){
				ans=i;
				break;
				
			}
			j++;
			if(i==1){
				cout<<"0";
				return 0;
			}
		}
		if(ans+j==aans){
			cout<<"0";
		}else if(ans+j+1==aans){
			cout<<"0";
		}
		return 0;
}
