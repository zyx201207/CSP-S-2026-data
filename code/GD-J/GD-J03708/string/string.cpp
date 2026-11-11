#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,char>> a(n);
	int h=0;
	for(int i=0;i<n;i++){
		int num;
		char letter;
		cin>>num>>letter;
		h+=num;
		a[i]={num,letter};
	}
	int nh=0;
//	cout<<h<<endl;
	int s=0;
	for(;s<n;s++){
		if(nh+a[s].first<h/2){
			nh+=a[s].first;
		}
		else if(nh+a[s].first==h/2){
			nh+=a[s].first;
			break;
		}else{
			a[s].first=a[s].first-(a[s].first+nh-(h+1)/2)*2;
			nh+=a[s].first;
			break;
		}
	}
	
//	cout<<nh<<endl;
	int ans=0;
//	for(int i=n-1;i>s;i++){
//		if(a[i].second!=a[n-i-1].second){
//			ans+=min(a[i].second,a[n-i-1].second)
//		}
//	}
	int l=0,r=n-1;
	while(nh){
		if(a[l].second!=a[r].second){
			ans+=min(a[l].first,a[r].first);
			nh-=min(a[l].first,a[r].first);
			int nj=min(a[l].first,a[r].first);
			a[l].first-=nj;
			a[r].first-=nj;
		}
		else{
			nh-=min(a[l].first,a[r].first);
			int nj=min(a[l].first,a[r].first);
			a[l].first-=nj;
			a[r].first-=nj;
//			cout<<l<<" "<<r<<endl;
		}
		if(a[l].first==0){
			l++;
		} 
		if(a[r].first==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}

