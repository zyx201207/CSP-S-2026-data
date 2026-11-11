#include<bits/stdc++.h>
using namespace std;
struct Node{
	int num,len;
}b[500500];
int n,m,a[500500],cnt,ans=0;
bool A=true,B=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(A&&a[i]!=i) A=false;
		if(B&&i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) B=false;
	}
	if(A){
		int k=m,l=0,sum=0;
		for(int i=1;i<=n;i++){
			sum++;
			if(sum<=k) l++,k-=sum;
			else break;
		}
		cout<<l;
		return 0;
	}
	if(B){
		int k=m,l=0,sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i]-a[i-1];
			if(sum<=k) l++,k-=sum;
			else break;
		}
		cout<<l;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i!=1&&a[i-1]==a[i]){
			b[cnt].len++;
		}else{
			b[++cnt].num=a[i];
			b[cnt].len=1;
		}
	}
	for(int i=1;i<=cnt;i++){
		int k=m,l=0;
		for(int j=i;j>=1;j--){
			if((b[i].num-b[j].num)*b[j].len<=k){
				k-=(b[i].num-b[j].num)*b[j].len;
				l+=b[j].len;
			}else if(b[i].num-b[j].num<=k){
				l+=k/(b[i].num-b[j].num);
				k%=(b[i].num-b[j].num);
				break;
			}else{
				break;
			}
		}
//		cout<<l<<endl;
		ans=max(l,ans);
	}
	cout<<ans;
	return 0;
}//90
