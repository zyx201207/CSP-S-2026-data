#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0,ans=0,m=0,l=0,h,t;
	int a[200000];
	char c[200000];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	h=n/2;
	if(cnt%2==1){
		ans=cnt/2;
		for(int i=0;;i++){
			if(m>ans){
				a[i-1]-=1;
				cnt-=1;
				break;
			}else{
				m+=a[i];
			}
		}
	}
	string s="",b="";
	cnt/=2;
	h=cnt;
	for(int i=0;;i++){
		if(cnt<a[i]){
			for(int j=0;j<cnt;j++){
				s+=c[i];
			}
			a[i]-=cnt;
			t=i;
			break;
		}else{
			for(int j=0;j<a[i];j++){
				s+=c[i];
			}
			cnt-=a[i];
		}
	}
	for(int i=t;i<n;i++){
		for(int j=0;j<a[i];j++){
			b+=c[i];
		}
	}
	for(int i=0;i<h;i++){
		if(s[i]!=b[h-i-1]){
			l++;
		}
	}
	cout<<l;
	return 0;
}
