#include<bits/stdc++.h>
using namespace std;
vector<long long> a(1);
long long id=0;
void findway(vector<long long>& x,long long end,long long da,long long step,long long d){
	if(da==end) a[id++]=step;
	long long sum=0;
	for(long long i=0;i<end-da;i++){
		sum+=x[da+i];
		if(sum<d){
			findway(x,end,da+1+i,step+1,d);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(long long time=0;time<t;time++){
		long long n,d,ans=0;
		cin>>n>>d;
		vector<long long> b(n);
		vector<long long> x(n);
		for(long long i=0;i<n;i++){
			cin>>b[i];
			if(i>0){
				x[i]=b[i]-b[i-1];
			}
		}
		for(long long i=0;i<n;i++){
			for(long long j=i+3;j<n;j+=3){
				ans++;
			}
		}
		cout<<ans<<endl;
/*      for(long long i=0;i<n-1;i++){
			for(long long j=i+1;j<n;j++){
				for(long long q=0;q<a.size();q++) a[q]=0;
				findway(x,j,i,0,d);
				sort(a.begin(),a.end());
				long long mi=9000000;
				long long sum=0;
				for(long long i=0;i<a.size();i++){
					if(a[i]!=0){
						mi=min(mi,a[i]);
					}
					if(a[i]==mi) sum++;
				}
				if(sum==2) ans++;
			}
		}
		cout<<ans<<endl;*/
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

