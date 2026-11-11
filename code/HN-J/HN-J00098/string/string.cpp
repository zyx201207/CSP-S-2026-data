#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
long long sum,aaa;
long long gg[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>gg[i]>>c[i];
		sum+=gg[i];
	}
	sum=sum-(sum+1)/2;
	int j=n,i=1;
	while(sum){
		if(c[j]!=c[i]){
			aaa+=min(gg[i],gg[j]);
		}
		if(sum<min(gg[i],gg[j])){
			aaa-=(min(gg[i],gg[j])-sum);
			break;
		}
		sum-=min(gg[i],gg[j]);
		if(gg[i]>gg[j]){
			gg[i]-=gg[j];
			j--;
		}else{
			gg[j]-=gg[i];
			i++;
		}
	}
	cout<<aaa;
} 
