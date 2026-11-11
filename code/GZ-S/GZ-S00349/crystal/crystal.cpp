//GZ-S00349 蒋承印 贵阳中天中学
#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,a[1000001]={};
long long cj=0,jc=0;
long long tj[1000001]={};
long long k=0,s=0;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		if(a[i]>a[j]){
			swap(a[i],a[j]);
		}
	}
}
for(int i=0;i<n;i++){
	tj[i]=a[i]-a[n/2];
}
for(int i=0;i<n/2;i++){
	cj=cj+tj[i];
	s++;
}
for(int i=n/2;i<n;i++){
	jc=jc+tj[i];
	k++;
}
for(int i=0;i<n;i++){
	if(a[i]==a[n/2]&&i<n/2){
		s++;
	}
	if(a[i]==a[n/2]&&n/2<i){
		k++;
	}
}
if(jc<cj){
	cout<<k+2;
}
if(cj<jc){
	cout<<s+2;
}
}
