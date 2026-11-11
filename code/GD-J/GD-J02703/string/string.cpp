#include<bits/stdc++.h>
using namespace std;
const int N=1e6+300;
char a[N],b[N],c;
int n,ans,cnt,k=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n!=0){
		k+=ans;
		cin>>ans>>c;
		ans+=k;
		for(int i=k;i<=ans;i++){
			a[i]=c;
		}
		n--;
	}
	cout<<500000;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
