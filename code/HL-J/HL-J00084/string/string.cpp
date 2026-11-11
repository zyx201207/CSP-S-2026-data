#include<bits/stdc++.h>
using namespace std;
const int N=200005;
map<char,long long> mp;
long long a[N],l[N],idx;
char c[N],ch[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]!=c[i-1]){
			l[++idx]+=a[i];
			ch[idx]=c[i];
		}
		else{
			l[idx]+=a[i];
		}
	}
	int sum=0;
	for(int i=1;i<=idx;i++){
		sum=l[i];
		for(int j=idx;j>i;j--){
			if(sum==0){
				break;
			}
			if(l[j]>sum){
				if(ch[j]==ch[i]){
					l[j]-=sum;
					l[i]-=sum;
					sum-=sum;
				}
				else sum-=sum;
			}
			else{
				sum-=l[j];
				if(ch[j]==ch[i]){
					l[i]-=l[j];
					l[j]=0;
				}
			}
		}
	}
	long long cnt=0,ma=0;
	for(int i=1;i<=idx;i++){
		cnt+=l[i];
	}
	sum=(cnt+1)/2;
	int ko;
	for(int i=1;i<=idx;i++){
		if(l[i]>sum){
			ko=i;
			break;
		}
		else sum-=l[i];
	}
	int be=(cnt+1)/2-sum+1,en=(cnt+1)/2-sum+l[ko],mid=(cnt+1)/2;
	l[ko]-=(min(mid-be+1,en-mid+1));
	cnt=0;
	for(int i=1;i<=idx;i++){
		mp[ch[i]]+=l[i];
		cnt+=l[i];
	}
	ma=0;
	for(char i='a';i<='z';i++){
		ma=max(ma,mp[i]);
	}
	cout<<cnt-ma;
	return 0;
}