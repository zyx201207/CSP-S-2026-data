#include<bits/stdc++.h>
using namespace std;
int n,x;
long long sum;
char c;
//long long sum,a1[200001],a2[200001],mid,i2,sum2;
//long long l,r,ans,qz1[200001],qz2[200001];
//char c1[200001],c2[200001];
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>c;
		while(x--)a+=c;
	}
	int m=a.length();
	for(int i=0;i<m/2;i++){
		if(a[i]!=a[m-i-1]) sum++;
		
	}
	cout<<sum;
	//	for(int i=1;i<=n;i++){
//		cin>>a1[i]>>c1[i];
//		sum+=a1[i];
//		qz1[i]=qz1[i-1]+a1[i];
//	}
//	mid=sum/2;
//	for(int i=n;sum2<=mid;i--){
//		a2[++i2]=a1[i];
//		c2[i2]=c1[i];
//		qz2[i2]-qz2[i2-1]+a2[i2];
//		sum2+=a1[i];
//	}
//	int j=1;
//	for(int i=1;i<=n-i2;i++){
//		l=qz1[i];
//		while(1){
//			r=qz2[j++];
//			if(r>=l){
//				if(c1[i]!=c2[j])ans+=r-l;
//				break;	
//			}
//			if(c1[i]!=c2[j])ans+=l-r;
//			
//		}
//	}
//	cout<<ans;
	
	
	
//	for(int i=1;i<=n-i2;i++){
//		cout<<a1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=i2;i++){
//		cout<<a2[i]<<" ";
//	}
	return 0;
}
