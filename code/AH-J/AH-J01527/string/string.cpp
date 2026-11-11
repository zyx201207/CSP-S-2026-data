#include<bits/stdc++.h>
using namespace std;
int n,l,a[200005],sum[200005],cnt;//---------------------------long long
string s[200005],s1,s2,s0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum[i]=sum[i-1]+a[i];
		s0+=s[i];
	}l=sum[n];
	double mid=(l+1)/2.0;double head=mid,tail=mid;int posh,post;
	for(int i=n;i>=1;i--){
		if(sum[i]<mid){
			head=sum[i]+1;
			posh=i+1;
			break;
		}
	}for(int i=1;i<=n;i++){
		if(sum[i]>=mid){
			tail=sum[i];
			post=i;
			break;
		}
	}double cha=0,shang=0;
	while(head>=1 && tail!=0 &&tail<=l){
		if(s[posh]==s[post]){
			if(tail==0 || head==0) break;
			cha=(tail-mid)-(mid-head);
			cnt+=cha;
			shang=cha;
			if(posh-2<0) break;
			head=sum[posh-2]+1;
			posh--;
			if(post+1>n) break;
			tail=sum[post+1];
			post++;
		}else{
			if(tail==0 || head==0) break;
			if(a[posh]<=a[post]){
				cnt+=a[posh]-shang;
				shang=a[posh]-shang;
				posh--;
				if(posh-1<0) break;
				head=sum[posh-1]+1;
			}else{
				cnt+=a[post]-shang;
				shang=a[post]-shang;
				post++;
				if(post>l) break;
				tail=sum[post];
			}
		}
		if(tail==0 || head==0) break;
	}
	if(tail<=l) cnt+=l-tail;
	cout<<cnt;
	return 0;
}
