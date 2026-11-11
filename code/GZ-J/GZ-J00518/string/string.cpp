//GZ-J00518 Íõè÷º­ 
#include<bits/stdc++.h>
using namespace std;

int n ,a[int(2e5+5)];
char b[int(2e5+5)];

long long l=1,r=0,ans=0,l_a,r_a,sum[int(2e5+5)];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum[i]=sum[i-1]+a[i];
		//cout<<sum[i]<<endl;
		r+=a[i];
	}
	l_a=1,r_a=n;
	
	//cout<<l_a<<'@'<<r_a<<endl;
	
	for(l,r ; l<r && l_a<r_a; ){
		
		if(l>sum[l_a])l_a++;
		if(r<=sum[r_a-1])r_a--;
		int x=sum[l_a]-l+1,y=r-sum[r_a-1];
		//cout<<x<<' '<<y<<endl;
		if(b[l_a]==b[r_a] && l_a!=r_a){
			l+=min(x,y),r-=min(x,y);
			if(l>sum[l_a])l_a++;
			if(r<=sum[r_a-1])r_a--;	
			//cout<<x<<'-'<<y<<endl;
			continue;
			
		}else{

			if(x>=y && l_a!=r_a){
				ans+=y;
				l+=y,r-=y;
				if(l>sum[l_a])l_a++;
				if(r<=sum[r_a-1])r_a--;
			//	cout<<x<<'+'<<y<<endl;
				continue;
				
			}else if(y>x && l_a!=r_a){
				ans+=x;
				l+=x,r-=x;
				if(l>sum[l_a])l_a++;
				if(r<=sum[r_a-1])r_a--;
			//	cout<<x<<'*'<<y<<endl;
				continue;
			}
		}
		//cout<<x<<'/'<<y<<endl;	
	}
	
	cout<<ans;
	
	return 0;
}
