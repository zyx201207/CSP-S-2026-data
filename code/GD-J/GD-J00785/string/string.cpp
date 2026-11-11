#include<bits/stdc++.h>
using namespace std;
int n;
long long sum1,sum2,cnt1,cnt2,ans;
pair<int,char> a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sum1=a[1].first,sum2=a[n].first,cnt1=a[1].first,cnt2=a[n].first;
	for(int i=1,j=n;i<j;){
		while(i<j && sum1<sum2){
			if(a[i].second!=a[j].second) ans+=cnt1;
			cnt2-=cnt1,cnt1=0;
			i++;
			cnt1+=a[i].first,sum1+=a[i].first;
		}while(i<j && sum1>sum2){
			if(a[i].second!=a[j].second) ans+=cnt2;
			cnt1-=cnt2,cnt2=0;
			j--;
			cnt2+=a[j].first,sum2+=a[j].first;
		}if(i<j && sum1==sum2){
			if(a[i].second!=a[j].second) ans+=cnt2;
			cnt1=0,cnt2=0;
			i++,j--;
			cnt1+=a[i].first,cnt2+=a[j].first;
			sum1+=a[i].first,sum2+=a[j].first;
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
