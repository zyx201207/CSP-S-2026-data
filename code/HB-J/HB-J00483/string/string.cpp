#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,num[N]={0};
char c[N];
long long he=0;
int main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j]){
			if(num[i]>num[j]){
				he+=num[j];
				num[i]=num[i]-num[j];
				j--;
			}else if(num[i]<num[j]){
				he+=num[i];
				num[j]=num[j]-num[i];
				i++;
			}else{
				he+=num[i];
				i++,j--;
			}
		}else{
			if(num[i]>num[j]){
				num[i]=num[i]-num[j];
				j--;
			}else if(num[i]<num[j]){
				num[j]=num[j]-num[i];
				i++;
			}else{
				i++,j--;
			}
		}
	}
	cout<<he;
	return 0;
}
