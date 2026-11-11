#include<bits/stdc++.h>
using namespace std;
const int x=200001;
long long a[x];
char s[x];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int N;
	cin>>N;
	if(N==1){
		cin>>a[0]>>s[0];
		cout<<0;
		return 0;
	}if(N>=2){
		if(N==2){
			cin>>a[0]>>s[0]>>a[1]>>s[1];
			if(s[1]==s[0]){
				cout<<0;
				return 0;
			}
			else{
				cout<<max(a[1],a[2])-min(a[1],a[2]);
				return 0;
			}
		}if(N>2){
			long long ans,sum;
			for(int i=0;i<N;i++){
				cin>>a[i]>>s[i];
				ans+=a[i];
			}
					
		}
	}
	return 0;
}
