#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500005],cha=a[2]-a[1];
bool check_dcsl(){    //deng cha shu lie.
	for(long long i=2;i<=n;i++){
		if((a[i]-a[i-1])!=cha)return false;
		cha=a[i]-a[i-1];
	}return true;
}
int main(){
	freopen("crystal.in","r",stdin);//bie wang le
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//long long an_exactly_m=0;
	//if(check_dcsl()){ //13-18,6 checkpoints in all,maybe a mark of 30.
		//cout<<"true"<<endl; //tiao shi
		check_dcsl();
		for(int i=1;i<=m;i+=cha){
			if(i>m)break;
			m-=i;
			//an_exactly_m+=i;
			ans=i;
		}
		cout<<ans;
	//}
	return 0;
}

