#include<bits/stdc++.h>
using namespace std;
long long  n,m1,m2,a[500010];
long long cha1[500001],cha2[500001],ans[500001],maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m1;
	m2=m1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	bool b;
	for(int i=3;i<=n;i++){
		int dengcha1,dengcha2;
		dengcha1=a[2]-a[1];
		dengcha2=a[i]-a[i-1];
		if(dengcha1!=dengcha2)break;
		if(i==n)b=1;
	}
	if(b){//te pan
		int dengcha=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m2-i*dengcha>=0)m2=m2-i*dengcha;
			else{
				cout<<i-1;
				return 0;
			}
		}
	}
	for(int i=1;i<=n-1;i++){
		cha1[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){//cha2=cha1
		cha2[i]=cha1[i];
	}
	for(int i=1;i<=n;i++){
		ans[i]=0;
		for(int i=1;i<=n-1;i++){//cha2=cha1
			cha2[i]=cha1[i];
		}
		m2=m1;	
		for(int j=i;j<=n;j++){
			if(cha2[j]<cha2[j+1]&&m2>=m2-(j-i+1)*(cha2[j+1]-cha2[j])){
				m2=m2-(j-i+1)*(cha2[j+1]-cha2[j]);
				for(int k=i;k<=j;k++){
					cha2[k]=cha2[j+1];
				}
			}
			if(m2<m2-i*(cha2[i+1]-cha2[i])||cha2[j]==cha2[j+1]||m2==0){
				for(int k=1;k<=j+2;k++){
					if(cha2[k]==cha2[j+1])ans[i]++;
				}
				break;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		if(ans[i]>=maxx){
			maxx=ans[i];
		}
	}cout<<maxx;

	return 0;
}
