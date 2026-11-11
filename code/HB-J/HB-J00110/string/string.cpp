#include<bits/stdc++.h>
using namespace std;
int n,a1,a2;
const int N=2e5+10;
long long a[N],sum,sum1,ans;
char c[N];
struct pp{
	int l;
	char z;
}s1[N],s2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(n==2){
		if(a[1]==a[2]){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	sum/=2;
	for(int i=1;i<=n;i++){
		sum1+=a[i];
		if(sum1>=sum){
			a1=i;
		}
	}
	sum1=0;
	for(int i=1;i<=a1;i++){
		if(sum1+a[i]>=sum){
			s1[i].l=sum-sum1;
			s1[i].z=c[i];
			break;
		}
		s1[i].l=a[i];
		s1[i].z=c[i];
		sum1+=a[i];
	}
	sum1=0;
	for(int i=1;i<=a1;i++){
		if(sum1+a[n-i+1]>=sum){
			s2[i].l=sum-sum1;
			s2[i].z=c[n-i+1];
			break;
		}
		s2[i].l=a[n-i+1];
		s2[i].z=c[n-i+1];
		sum1+=a[n-i+1];
	}
	for(int i=1,j=1;i<=a1&&j<=a1;){
		if(s1[i].l>=s2[j].l){
			if(s2[j].z!=s1[i].z){
				ans+=s2[j].l;
				s1[i].l-=s2[j].l;
				j++;
				
				if(s1[i].l==0){
					i++;
				}
				continue;
			}
			s1[i].l-=s2[j].l;
			j++;
			
		}
		if(s1[i].l<s2[j].l){
			if(s2[j].z!=s1[i].z){
				ans+=s1[i].l;
				s2[j].l-=s1[i].l;
				i++;
				
				if(s2[j].l==0){
					j++;
				}
				continue;
			}
			s2[j].l-=s1[i].l;
			i++;
			
		}
	}
	cout<<ans;
	return 0;
}
