#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans,sum,cnt;
char c[200010];
stack<int> st;
queue<int> q;
signed main(){
	freopen("string,in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i]; 
	} 
	ans/=2;
	//cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		cnt+=a[i]; 
		if(cnt>=ans){
			cnt=i;
			break;
			//for(int j=1;j<=i;j++){
				//for(int k=1;k<=a[j];k++){
					//st.push(c[j]);
				//	continue;
				//}
		//	}
		//	for(int j=i;j<=n;j++){
			//	for(int k=1;k<=a[j];k++){
				//	q.push(c[j]);
				//	continue;
				//}
			//}
		}
	} 
	for(int i=1;i<=cnt;i++){
		st.push(c[i]);
	}
	q.empty();
	for(int i=cnt+1;i<=n;i++){
		q.push(c[i]);
	}
	for(int i=1;i<=st.size();i++){
		if(st.top()!=q.front()){
			sum+=a[i];
			st.pop();
			q.pop();
			//cout<<sum<<endl;
		}
	}
	cout<<sum;
	return 0;
}
