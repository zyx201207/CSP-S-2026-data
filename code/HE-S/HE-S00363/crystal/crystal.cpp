#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50000005],s=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	long long mid=(1+n)/2;
	long long l=mid-1;
	long long r=mid+1;
	while(m>0){
		if(m>(a[mid]-a[l])&&m-((a[r]-a[mid])+(a[mid]-a[l]))>=0){
			s+=2;
			m-=((a[mid]-a[l])+(a[r]-a[mid]));
			l--;
			r++;
		}
		else if(m>=(a[mid]-a[l])&&m-(a[mid]-a[l])>=0){
			s++;
			m-=a[mid]-a[l];
			l--;
		}
		else if(m>=(a[r]-a[mid])&&m-(a[r]-a[mid])>=0){
			s++;
			m-=a[r]-a[mid];
			r++;
		}
		else
			break;
	}
	cout<<s;
	return 0;
} 
