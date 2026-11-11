#include<bits/stdc++.h>
using namespace std;
int n;
long long a[1000002];
char c[1000002];
long long l,r;
long long num,num1,cu,cu1;
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i>=2){
			if(c[i]!=c[i-1]){
				f=true;
			}
		}
	}
	if(!f){
		cout<<0;
		return 0;
	}
	l=1,r=n;
	long long ans=0;
	num=a[l];
	cu=c[l];
	num1=a[r];
	cu=c[r];
	while(l<r){
		long long w=0;
		if(num>num1){
			w=num-num1;
			if(cu==cu1){
				ans+=w;
			}else{
				ans+=num1;
			}
			r--;
			num-=num1;
			num1=a[r];
			cu1=c[r];
		}else if(num<num1){
			w=num1-num;
			if(cu==cu1){
				ans+=w;
			}else{
				ans+=num;
			}
			l++;
			num1-=num;
			num=a[l];
			cu=c[l];
		}else if(num==num1){
			if(cu!=cu1){
				ans+=num;
			}
			l++,r--;
			num=a[l];
			num1=a[r];
			cu=c[l];
			cu1=c[r];
		}
	}
	cout<<ans;
	return 0;
}
