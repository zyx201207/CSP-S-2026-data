#include<bits/stdc++.h>
using namespace std;
string s;
long long sum,l,n,a[200086],hz,mid,q,h,qw,hw,minn;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	hw=n+1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		s=s+c;
		l+=a[i];
	}
	mid=l/2;
	while(hz<mid){
		if(q==0){
			q=a[++qw];
		}
		if(h==0){
			h=a[--hw];
		}
		minn=min(q,h);
		//cout<<q<<' '<<h<<' '<<qw<<' '<<hw<<' '<<hz<<' ';
		hz+=minn;
		if(qw==hw){
			break;
		}
		if(s[qw-1]!=s[hw-1]){
			if(hz>=mid){
				sum=sum+q+h-2*min(q,h);
				break;
			}
			sum+=min(q,h );
		}
		//cout<<min(q,h)<<' '<<sum<<endl;
		a[qw]-=minn;
		a[hw]-=minn;
		q-=minn;
		h-=minn;
	}
	cout<<sum;
	return 0;
}
