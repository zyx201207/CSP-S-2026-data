#include<bits/stdc++.h>
using namespace std;
char l2[3123243],l2a[314231],l2b[312324]; 
long long l[423433]={0},la[324132],lb[432443]; 
long long n,m=0,ans=0,c=0,d=0,e=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char b; 
		cin>>a>>b;
		m+=a;
		l[i]=a;
		l2[i]=b;
	}e=m%2;
	m/=2;
	for(int i=1;i<=n;i++){
		if(l[i]<=m){
			m-=l[i];
			la[i]=l[i];
			l2a[i]=l2[i];
			c++;
		}
		if(m==0){
			l[i+e]--;
			l2[i]--;
			m=i;
			if(l[i+e]==0){
				m++;
			}
			break;
		}
		if(l[i]>m){
			l[i]-=m;
			la[i]=m;
			l2a[i]=l2[i];
			c++;
			break;
		}
	}for(int i=n;i>m;i--){
		lb[n-i+1]=l[i];
		l2b[n-i+1]=l2[i];
		d++;
	}int i=1,j=1;
	while(i<=c && j<=d){
		if(la[i]>lb[j]){
			if(l2a[i]==l2b[j]){
				la[i]-=lb[j];
				lb[j]=0;
				j++;
			}else{
				la[i]-=lb[j];
				ans+=lb[j];
				lb[j]=0;
				j++;
			}
		}else if(la[i]<lb[j]){
			if(l2a[i]==l2b[j]){
				lb[j]-=la[i];
				la[i]=0;
				i++;
			}else{
				ans+=la[i];
				lb[j]-=la[i];
				la[i]=0;
				i++;
			}
		}else{
			if(l2a[i]==l2b[j]){
				la[i]=0;
				lb[j]=0;
				i++;
				j++;
			}else{
				ans+=la[i];
				la[i]=0;
				lb[j]=0;
				i++;
				j++;
			}
		}
	}cout<<ans;
	return 0;
}
