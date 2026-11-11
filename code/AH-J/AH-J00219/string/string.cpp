#include<bits/stdc++.h>
#define int long long  
using namespace std;
int ans;
int n,m;
int a[500005];
char s[500005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		m+=a[i];
//		cout<<m<<endl;
	}
	int sum=0,u;
	for(int i=1;i<=n;i++){
		u=i;
		sum+=a[i];
		if(sum==m/2){
			break;
		}
		if(sum>m/2){
			n++;
			for(int j=n;j>=i+2;j--){
				a[j]=a[j-1],s[j]=s[j-1];
			}
			a[i+1]=sum-m/2;
			s[i+1]=s[i];
			a[i]-=a[i+1];
			sum=m/2;
			break;
		}
	}//确保存在i,使a1+a2+a3+...+ai=m/2 
	if(m%2==1){
		a[u+1]--;
		m--;
	}
//	cout<<m<<" "<<sum;
//	cout<<1;
	int l=0,r=m+1;//l=左指针当前遍历的上一个 ,r=右指针当前遍历的上一个
	for(int i=1,j=n;/*i<=u&&j>u*/;){
		//cout<<i<<" "<<j<<" "<<l<<" "<<r<<endl;
		if(l==sum){
			if(r>sum+1){
				if(s[i-1]!=s[j]){
					ans=ans+(r-sum-1);
				}
			}
			break;
		}if(r==sum+1){
			if(l<sum){
				if(s[i]!=s[j-1]){
					ans=ans+(sum-l);
				}
			}
			break;
		}
		if(a[i]==a[j]){
				if(s[i]==s[j]){
					l=l+a[i];
					r=r-a[j];
					i++,j--;
					continue;
				}
				else{
					ans+=a[i];
					l=l+a[i];
					r=r-a[j];
					i++,j--;
					continue;	
				}
			}
		if(a[i]>a[j]){
				if(s[i]==s[j]){
					a[i]-=a[j];
					l+=a[j],r-=a[j];
					j--;
				}
				else{
					ans+=a[j];
					a[i]-=a[j];
					l+=a[j],r-=a[j];
					j--;
				}
			}
		if(a[i]<a[j]){
				if(s[i]==s[j]){
					a[j]-=a[i];
					l+=a[i],r-=a[i];
					i++;
				}
				else{
					ans+=a[i];
					
					a[j]-=a[i];
					l+=a[i],r-=a[i];
					i++;
				}
			}
	}
    cout<<ans;
	return 0;
}
