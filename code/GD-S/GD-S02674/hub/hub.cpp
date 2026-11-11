#include<iostream> 
using namespace std;
long long s,m,an,a[1000002],mi,mm,zmm;
int dp(){
	a[0]=-111111;
	for(int i=1;i<=s;i++){
		for(int j=i+1;j<=s;j++){
			if(a[j]-a[i]<mi&&a[i]!=-111111){
				mi=a[j]-a[i];
				mm=i;
				zmm=j;
			}
		}
	}
	a[mm]=-111111;
	a[zmm]=-111111;
	return mi;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>s>>m;
	for(int i=1;i<=s;i++)cin>>a[i];
	for(int i=1;i<=s;i++){
		int maa=-111111,mama;
		for(int j=1;j<=s-i+1;j++){
			if(maa<a[j]){
		 		mama=j;
				maa=a[j];
			}
		} 
		int zx=a[s-i+1];
		a[s-i+1]=maa;
		a[mama]=zx;
	}
	while(m>0){
		mm=111111;
		zmm=111111;
		mi=111111;
		int iiiiiiiiii=dp();
		if(m>mi){
			m-=mi;
			an++;
		}else if(dp()<m){
			m-=mi;
			an++;
		}else {
			break;
		}
		
	}
	cout<<an;
} 
