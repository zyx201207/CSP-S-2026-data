#include<bits/stdc++.h>
using namespace std;
struct node{
	int sum;
	char x;
};//
int n;
int a[200005];
char c[200005];
queue<node> l,r;
unsigned long long sum=0,lsum=0,rsum=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
//	cout<<"\n\n";
	for(int i=1;i<=n;i++){
		if(lsum+a[i]<=sum/2){
			l.push({a[i],c[i]});
			lsum+=a[i];
//			cout<<a[i]<<" "<<c[i]<<"\n";
		}else{
			if(sum/2-lsum!=0){
				l.push({sum/2-lsum,c[i]});
			}
//			cout<<sum/2-lsum<<" "<<c[i]<<"\n\n";
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(rsum+a[i]<=sum/2){
			r.push({a[i],c[i]});
			rsum+=a[i];
//			cout<<a[i]<<" "<<c[i]<<"\n";
		}else{
			if(sum/2-rsum!=0){
				r.push({sum/2-rsum,c[i]});
			}
//			cout<<sum/2-rsum<<" "<<c[i]<<"\n";
			break;
		}
	}
	while(!l.empty()){
		node lt=l.front();
		node rt=r.front();
		if(lt.x!=rt.x){
			ans+=min(lt.sum,rt.sum);
		}
		if(lt.sum==rt.sum){
			l.pop();
			r.pop();
		}else if(lt.sum<rt.sum){
			r.front().sum-=l.front().sum;
			l.pop();
		}else if(lt.sum>rt.sum){
			l.front().sum-=rt.sum;
			r.pop();
		}
	}
	cout<<ans;
	return 0;
}

