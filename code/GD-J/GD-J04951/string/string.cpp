#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	vector<pair<int,char> > a(n);
	long long lens=0;
	int t1;
	char t2;
	for (int i=0;i<n;i++){
		cin >> a[i].first>>a[i].second;
		lens+=a[i].first;
	}
	
	vector<pair<int,char> > b1;
	vector<pair<int,char> > b2;
	long long lens1=0;
	long long lens2=0;
	for (int i=0;lens1<=lens/2;i++){
		b1.push_back(a[i]);
		lens1+=a[i].first;
	}
	for (int i=n-1;lens2<=lens/2;i--){
		b2.push_back(a[i]);
		lens2+=a[i].first;
	}
	if (lens1>lens/2){
		b1[b1.size()-1].first-=lens1-lens/2;
		
	}
		
	
	
	if (lens2>lens/2){
		b2[b2.size()-1].first-=lens2-lens/2;
		
	}
	long long cnt=0;
	long long tz=b2.size()-1;
	for (int i=0;i<b1.size();i++){
		int num=b1[i].first;
		while(num>0){
			if (b2[tz].first>num){
				b2[tz].first-=num;
				if (b2[tz].second!=b1[i].second){
					cnt += num;
				}
			}
			else{
				if (b2[tz].second!=b1[i].second){
					cnt += b2[tz].first;
				}
				num-=b2[tz].first;
				b2[tz].first==0;
				tz-=1;
			} 
			if (b2[tz].first<=0){
				tz-=1;
			}
		}
	}
	cout << cnt << endl;
	
	return 0;
} 
