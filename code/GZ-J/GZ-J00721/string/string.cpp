//GZ-J00721 贵阳市第三实验中学 刘子轩 
#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
char a[200003];
int len,tl,n,l,r,steplen,sum,tc;
char lle,rle;
int walll[200003];
int maxlen(int ll,int rr){
	int tepl,tepr,rrlen=0;
	for(int i=1;i<=tc;i++){
		if(walll[i]>ll){
			tepl=walll[i]-ll;
			break;
		}
	}
	for(int i=tc-1;i>=1;i--){
		if(walll[i]<=rr){
			tepr=rr-walll[i]+1;
			break;
		} 
	}
	rrlen=min(tepl,tepr);
	return rrlen;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld",&tl);
		cin>>a[i];
		len+=tl;
		walll[++tc]=walll[tc-1]+tl;
	}
	r=len-1;
	len=len/2;
	l=0;
	walll[0]=1;
	while(l<len){
		for(int i=1;i<=n;i++){
			if(l<walll[i]){
				lle=a[i-1];
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(r+1>=walll[i]){
				rle=a[i-1];
				break;
			}
		}
		//cout<<lle<<" "<<rle<<endl;
		steplen=maxlen(l,r);
		if(lle!=rle){
			sum+=steplen;
		}
		l+=steplen;
		r-=steplen;
	}
	cout<<sum;
	return 0;
}

