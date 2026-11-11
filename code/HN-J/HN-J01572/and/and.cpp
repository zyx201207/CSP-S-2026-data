#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200010;
int n,m,ma=0;
int s[N],r[N],dp[N],boo[N];
/*void tff(int l,int r){
	int mid=(l+r)/2;
	if(l==r) return;
	tff(l,mid);
	tff(mid+1,r);
	int sum=l;
	int i=l,j=r,k=mid+1;
	while(i<k&&k<=j){
		if(s[i]>=s[k+1]){
			r[sum++]=s[i];
			i++;
		}else{
			r[sum++]=s[j];
			j++;
		}
	}
	while(i<k){
		r[sum++]=s[i];
		i++;
	}
	while(k<=j){
		r[sum++]=s[k];
		k++;
	}
	for(int q=l;q<=r;q++) s[q]=r[q];
}*/
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		/*if(s[i]>dp[1]){
			dp[1]=s[i];
			boo[ma]=0;
			ma=i;
			boo[ma]=1;
		}*/
	}
	/*for(int i=2;i<=m;i++){
		ma=0;
		for(int j=1;j<=n;j++){
			if(boo[j]==0){
				if(dp[i]<=(dp[i-1]&s[j])){
					dp[i]=dp[i-1]&s[j];
					boo[ma]=0;
					ma=j;
					boo[ma]=1;
				}
			}
		}
	}
	cout<<dp[m];*/
	//tff(1,n);
	sort(s+1,s+1+n,greater<int>());
	cout<<s[m];
	return 0;
	//Trick||Treat!
	//16	11	D:\HN-J01572\and\and.cpp	[Error] invalid types 'int[int]' for array subscript
}
