#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],o,u;
	//vector <int> o;
	//priority_queue<int> p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1,t=0;
	for(int i=1;i<=n;i++){
		s+=(a[i]-a[i-1])*(i-1);
		t=i;
		if(s>m){s-=(a[i]-a[i-1])*(i-1);
			break;
		}o++;
	}
	//cout<<t;
	for(int i=t;i<=n;i++){
		//cout<<"   "<<-(a[i]-a[j])+(o)*(a[i]-a[i-1]);
		s=s-(a[i]-a[j])+(o)*(a[i]-a[i-1]);
		while(s<=m&&j>=1){
			s+=a[i]-a[j];
			if(s>m){
				s-=a[i]-a[j];
				break;
			}
			j--;
			o++;
		}
		//cout<<";;;;"<<o<<" "<<s<<"  "<<endl;
		j++;
		
	}
	cout<<o;
} 
