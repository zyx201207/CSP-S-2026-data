#include<bits/stdc++.h>
#define N 200050
using namespace std;
char c[N];
long long n,head[N],cnt,a[N],last;
long long sum;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(i=1;i<=n;i++){
		head[i]=a[i-1]+1;
		a[i]+=a[i-1];
//		cout<<"_ i:"<<i<<" : "<<a[i]<<"\n";
		if(a[i]>(sum+1)/2){
			a[i]=(sum+1)/2*2-a[i]+(sum%2==0);
			last=i;
			if(a[i]<head[i]){
				last--;
	//			cout<<i<<" : a is "<<a[i]<<"\n";
	//				if(c[--last]!=c[i])cnt+=head[i]-a[i];
	//				a[last]=a[i]-1;
	//				cout<<"cnt :"<<cnt<<"\n";
	//			}
				while(a[i]<head[last]){
	//				cout<<i<<" : a is "<<a[i]<<" last.h is "<<head[last]<<"\n";
					if(c[i]!=c[last]){
						cnt+=a[last]-head[last]+1;
					}
					head[i]=head[last]-1;
					last--;
				}
				if(c[i]!=c[last])cnt+=head[i]-a[i];
				a[last]=a[i]-1;
			}
			else if(a[i]==head[i])last--;
//			a[i];
			i++;
			break;
		}
	}
	for(;i<=n;i++){
		head[i]=a[i-1]-1;
		a[i]=a[i-1]-a[i];
//		cout<<"_ i:"<<i<<" : "<<a[i]<<"\n";
		while(a[i]<head[last]){
//			cout<<i<<" : a is "<<a[i]<<" last.h is "<<head[last]<<"\n";
			if(c[i]!=c[last]){
				cnt+=a[last]-head[last]+1;
			}
			head[i]=head[last]-1;
			last--;
		}
		if(c[i]!=c[last])cnt+=head[i]-a[i]+1;
		a[last]=a[i]-1;
//		cout<<"cnt :"<<cnt<<"\n";
	}
	cout<<cnt;
	return 0;
}
