#include<bits/stdc++.h>
using namespace std;
long long n,m;//m ²Ù×÷ 
long long a[500005],b[500005];//b²î·Ö 
long long ans=0;
bool cmp(int x,int y){
	return x<y;
}
void lin(long d,long long shu,long long x){
	if(d>m){
		ans=max(ans,shu);
		return;
	}
	if(x>n){
		ans=max(ans,shu);
		return;
	}
	shu++;
	if(d+b[shu]*shu<=n){
		lin(d+b[shu]*shu,shu,x++);	
	}
	shu--;
	lin(d,shu,x++);
}
bool jian(int h){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			return 0;
		}
	}
	return 1;
}
bool cha(int g){
	for(int i=1;i<n;i++){
		if(b[i]!=b[i+1])
		return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=a[i+1]-a[i];
	//	cout<<b[i]<<"  ";
	}
	
		if(jian(n)){
		int cnt=1;
		int z=m;
		for(int i=1;i<=m;i++){
			if(z-i>=0){
				cnt++;
				z=z-i;
			}
		}
		cout<<cnt;
		return 0;
	}
	 if(cha(n)){
		int x=a[2]-a[1];
		cout<<m/x;
		return 0;
	}
			
		for(int i=1;i<=n;i++){
			int z=m;
			long long cnt=1;
			for(int j=i;j<n;j++){
				if(b[j]*cnt<=z&&z>=0){
					z-=b[j]*cnt;
					cnt++;
					
				//	cout<<z<<"  ";
				}
			}
		//	cout<<endl<<"cnt"<<cnt<<"  ";
			ans=max(ans,cnt);
		}
		cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
