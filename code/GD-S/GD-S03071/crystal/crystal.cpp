#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],b[500001],max1=0,max_num,num;
bool l1;
int s(int num){
	if(num<0){
		l1=0;
		return -num;
	}
	else return num;
}
int s1(int i,int k){
	if((i*k)/m){
		num+=(i*k)/m;
		return (i*k)%m;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x<0){
			x=sqrt(x);
			b[x]++;
			if(b[x]>max1){
				max1=b[x];
				max_num=-x;
			}
		}
		else{
			a[x]++;
			if(a[x]>max1){
				max1=x;
				max_num=x;
			}
		}
	}
	int l=1,r=1;
	num=max1;
	l=s(max_num)-1;
	r=s(max_num)+1;
	for(int i=s(max_num);i<m;i++){
		
		if(l1){
			if(a[r]>=1){
				i+=s1(a[i+1],i+1);
				r++;
			}
			if(l<=0){
				if(b[l]>=1){
					i+=s1(b[i+1],i+1);
					l++;
				}
			}
			else{
				if(a[i+1]>=1){
				i+=s1(a[i-1],i+1);
				i++;
			}
			}
		}
	}
	cout<<num;
	return 0;
}
