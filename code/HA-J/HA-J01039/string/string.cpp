#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a,zongshu=0,ans=0,m1=0;
	cin>>n;
	long long shu[n],shu_ty[n];
	string c,eng[n];
	for(long long i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		shu[i]+=a;
		eng[i]+=c;
	}
	for(long long i=1;i<=n;i++){
		ans=0;
		for(long long j=i+1;j<=n;j++){
			if(eng[i]==eng[j]){
				ans++;	
			}else{
				break;
			}
		}
		m1=0;
		if(ans==n-1){
			cout<<0;
			return 0;
		}
		if(ans!=0){
			for(long long m=i;m<=i+ans;m++){
				m1+=shu[m];
			}
				shu_ty[i]+=m1;
				i+=ans;
		}else{
			shu_ty[i]+=shu[i];
		}
	}
	
	long long n_ty=sizeof(shu_ty);
	zongshu+=shu_ty[n_ty];
	long long maxn=0;
	for(long long x=2;x<=n_ty-1;x++){
		zongshu+=shu_ty[x];
		if(shu_ty[x]>=maxn){
			maxn=shu_ty[x];
		}
	}
	cout<<zongshu-maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
