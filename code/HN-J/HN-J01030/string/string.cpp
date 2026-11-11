#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+1e4;
long long number[maxn];
char c[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>number[i]>>c[i];
	}
	long long ans=0;
	for(int i=1,j=n;i<=j;){
		if(number[i]>number[j]){
			number[i]-=number[j];
			if(c[i]!=c[j]) ans+=number[j];
			j--;
		}
		else if(number[i]<number[j]){
			number[j]-=number[i];
			if(c[i]!=c[j]) ans+=number[i];
			i++;
		}
		else{
			if(c[i]!=c[j]) ans+=number[i];
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
