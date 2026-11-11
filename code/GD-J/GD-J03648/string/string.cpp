#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
	}
	int l=1,r=n,now1=a[1],now2=a[n];
	long long sum=0;
	while(l<=r){
		if(now1<now2){
			if(b[l]!=b[r])sum+=now1;
			now2-=now1;
			now1=a[l++];
		}else if(now1>now2){
			if(b[l]!=b[r])sum+=now2;
			now1-=now2;
			now2=a[r--];
		}else{
			if(b[l]!=b[r])sum+=now2;
			now1=a[l++];
			now2=a[r--];
		}
	}
	cout<<sum;
	return 0;
}
