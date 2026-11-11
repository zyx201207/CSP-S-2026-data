#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	string l;
};
int n;
long long a[200005],ans;
string c[200005];
node m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int i=0,j=n-1;
	bool b;
	if(a[i]>=a[j]){
		if(c[i]!=c[j]){
			ans+=a[j];
		}
		m.l=c[i];
		m.num=a[i]-a[j];
		j--;
		b=0;
	}
	else{
		if(c[i]!=c[j]){
			ans+=a[i];
		} 
		m.l=c[j];
		m.num=a[j]-a[i];
		i++;
		b=1;
	} 
	while(i<j){
		if(b){
			if(m.l!=c[i]){
				ans+=abs(m.num-a[i]);
			}
			if(m.num<a[i]){
				m.l=c[i];
				b=0;
				m.num=abs(m.num-a[i]);
				j--;
			} 
			else{
				m.num=abs(m.num-a[i]);
				i++;
			}
			
		}
		else{
			if(m.l!=c[j]){
				ans+=abs(m.num-a[j]); 
			}
			if(m.num<a[j]){
				m.l=c[j];
				b=1;
				m.num=abs(m.num-a[j]);
				i++;
			}
			else{
				m.num=abs(m.num-a[j]);
				j--;
			}
			
		}
	}
	cout<<ans;
	return 0; 
}
