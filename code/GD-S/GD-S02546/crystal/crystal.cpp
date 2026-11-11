#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+9;
ll n,m;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	int flag = 1;
	sort(a+1,a+1+n);
	while(m){
		for(int i=1;i<n;i++){
			if(i>flag||m<flag)break;
			if(a[flag] == a[flag+1]){
				//cout<<"do"<<endl;
				flag = i+1;
				continue;
			}
			if(a[flag]<a[flag+1]){
				/*
				cout<<a[i]<<"->";
				a[i]++;
				cout<<a[i]<<" "<<flag<<endl;
				m--;*/
				for(int j=1;j<=flag;j++){
					//cout<<a[j]<<"->";
					a[j]++;
					//cout<<a[j]<<" "<<flag<<endl;
					m--;
				}
			}
			
			
		}	
		//cout<<"test:";
		//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
		//cout<<endl;
		if(m<flag)break;
	}
	//cout<<endl;
	//int same = a[flag];
	int sum = 0;
	for(int i=flag+1;i<=n;i++){
		if(a[i] == a[flag]+1){
			sum++;
		}
		if(a[i] == a[flag]){
			flag++;
		}
		else break;
	}
	if(sum+m>flag)cout<<sum+m;
	else cout<<flag;
	
	return 0;
} 
