#include<bits/stdc++.h>
using namespace std;
long long len[200005],n,ans;
char wen[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char ai;
		cin>>a>>ai;
		len[i]=a;
		wen[i]=ai;
	}
	long long i=1,j=n;
	while(i<j){
		if(len[i]>len[j]){
			len[i]-=len[j];
			if(wen[i]!=wen[j]) ans+=len[j];
			j--;
		}
		if(len[i]<len[j]){
			len[j]-=len[i];
			if(wen[i]!=wen[j]) ans+=len[i];
			i++;
		}
		if(len[i]==len[j]){
			if(wen[i]!=wen[j]) ans+=len[i];
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
