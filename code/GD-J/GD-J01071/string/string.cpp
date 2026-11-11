#include<bits/stdc++.h>
using namespace std;
int n,b;
long long ans=0;
int cnt[200];
struct data{
	long long s;
	char c;
}a[210000];
void jia(int a){
	int c=0,cnt1[200];
	for(int i=0;i<30;i++){
		cnt1[i]=0;
	}
	while(a>0){
		cnt1[c]=a%10;
		a/=10;
		c++;
	}
	b=max(b,c);
	int d=0;
	for(int i=0;i<=b;i++){
		cnt[i]+=cnt1[i]+d;
		if(cnt[i]>=10){
			d=1;
			cnt[i]-=10;
		}else{
			d=0;
		}
	}
	if(cnt[b]!=0){
		b++;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				r--;
			}else if(a[l].s<a[r].s){
				a[r].s-=a[l].s;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].s>a[r].s){
				a[l].s-=a[r].s;
				jia(a[r].s);
				r--;
			}else if(a[r].s>a[l].s){
				a[r].s-=a[l].s;
				jia(a[l].s);
				l++;
			}else{
				jia(a[l].s);
				r--;
				l++;
			}
		}
	}
 	if(cnt[b]==0&&b==0){
		cout<<0;
		return 0;
	}
	for(int i=b-1;i>=0;i--){
		cout<<cnt[i];
	}
	return 0;
}

