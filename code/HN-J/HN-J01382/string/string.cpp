#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200100;
int len[N],start[N],a[N];
int ans=0,length,n;
char b[N];
int Find_len(int purpose){
	int mid,l=1,r=length;
	while(l<=r){
		mid=((l+r)>>1);
		if(start[mid]<=purpose){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return l-1;
}
int diff(char c,int l,int r){
	int sum_a=0;
	int sta=Find_len(l),end=Find_len(r);
	for(int i=sta;i<=end;i++){
		if(i==sta&&b[sta]!=c){
			sum_a+=len[sta]-l+1;
		}else if(i==end&&b[end]!=c){
			sum_a+=r-start[end]+1;
		}else if(b[i]!=c){
			sum_a+=a[i];
		}
	}
	return sum_a;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		len[i]=a[i]+len[i-1];
		start[i]=len[i-1]+1;
	}
	length=len[n];
	int mids=length/2;
	int before;
	int under=Find_len(mids);//under当前块的下标 
	for(int i=under;i>=1;i--){
		before=start[i];
		ans+=diff(b[i],mids+(mids-before),mids+(mids-before)
		+a[i-1]);
	}
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
