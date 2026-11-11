#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],sum=0,lnt=0,rnt=0,anss=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int l=(sum%2?(sum-1)/2+1:sum/2+1);
	
	if(sum%2==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=a[i];
			if(cnt==sum/2)break;
			if(cnt>sum/2){
				for(int j=n;j>i;j--)a[j+1]=a[j],c[j+1]=c[j];
				a[i+1]=cnt-sum/2,c[i+1]=c[i];
				a[i]-=(cnt-sum/2);
				n+=1;
				break;
			}
		}
	}else{
		int cnt=0;
		const int aa=(sum-1)/2+1;
		for(int i=1;i<=n;i++){
			cnt+=a[i];
			if(cnt==aa)break;
			if(cnt>aa){
				int l=aa-(cnt-a[i])-1;
				int r=a[i]-l-1;
				if(l==0||r==0){
					for(int j=n;j>i;j--)a[j+1]=a[j],c[j+1]=c[j];
					if(l==0)a[i+1]=a[i]-1,a[i]=1,c[i+1]=c[i]; 
					if(r==0)a[i+1]=1,a[i]-=1,c[i+1]=c[i]; 
					n+=1;
				}else{
					for(int j=n;j>i;j--)a[j+2]=a[j],c[j+2]=c[j];
					a[i]=l,a[i+1]=1,a[i+2]=r,c[i+1]=c[i],c[i+2]=c[i];
					n+=2;
				}
				//for(int j=1;j<=n;j++)cout<<a[j]<<' '<<c[j]<<endl;
				break;
			}
		}
	}
	
	int i,j=n;
	for(i=1;i<=n;i++){
		int ans=0;
		if(lnt+a[i]<l){
			lnt+=a[i];
			int jcf=j;
			while(rnt+a[j]<=lnt&&rnt+a[j]<l){
				rnt+=a[j];
				j--;
			}
			//cout<<i<<' '<<lnt<<' '<<rnt<<endl;
			if(lnt!=rnt){
				if(c[j]!=c[i])ans+=(lnt-rnt);
				a[j]-=(lnt-rnt);
				rnt=lnt;
			}
			int lft=a[i];
			for(int k=j+1;k<=jcf;k++){
				lft-=a[k];
				if(c[k]!=c[i])ans+=a[k];
			}
		}
		anss+=ans;
	}
	cout<<anss;
	return 0;
} 
