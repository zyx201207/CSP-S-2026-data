#include<bits/stdc++.h>
using namespace std;
long long cha[500007],way[500002],ans,cnt=-1,what[500005];
int n,m,a[500007];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;++i){
        way[i]=a[i+1]-a[i];     
	}

	for(int i=2;i<=n;++i){
        what[i]=what[i-1]+(i-1)*abs(way[i-1]);
	}
//	for(int i=1;i<=n;++i){
      //  cout<<what[i]<<" ";
	//}

	for(long long i=1;i<=n;++i){
		for(long long j=i+1;j<=n;++j){
			ans=(what[j]-what[i]);
			if(ans==m){
				cnt=max(cnt,(j-i+1));
			//	cout<<j<<i<<"  "<<cnt<<endl;
				continue;
			}
			if(ans>m){
				cnt=max(cnt,(j-i));
			//	cout<<" "<<j<<i<<"  "<<cnt<<endl;
				break;
			}
        }
	}
	printf("%d",cnt);
}


