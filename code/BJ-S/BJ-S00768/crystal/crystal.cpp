#include<bits/stdc++.h>
using namespace std;
int n,ans1=0,ans2=0;
vector<int> a;
map<int,int> map_;
unsigned long long m1,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		map_[x]++;
		a.push_back(x);
	}
	int max_num=a[0];
	sort(a.begin(),a.begin()+n);
	if(n>=1e4){
	max_num=a[n/2];
	m=m1;
	for(int i=n/2;i>=0;i--){
        if(a[i]!=max_num){
            int need=max_num-a[i];
            if(m>=need){
            m-=need;}
            else break;
            ans1++;
        } else {
            ans1++;
        }
	}

    m=m1;
	max_num=a[0];
	for(int i=0;i<n;i++)
		if(map_[max_num]<=map_[a[i]]) max_num=a[i];
	int q1=0;
	cout<<"\n";
	while(a[q1]!=max_num) q1++;
	do{
        q1++;
	}while(a[q1]==max_num);
    for(int i=q1;i>=0;i--){
        if(a[i]!=max_num){
            int need=max_num-a[i];
            if(m>=need){
            m-=need;}
            else break;
            ans2++;
        } else {
            ans2++;
        }
    }
    cout<<max(ans1,ans2);
	}


    max_num=-1;
    if(n<1e4){
    m=m1;
    for(int i=0;i<n;i++){
        unsigned long long x=0;
        int y=0;
            for(int j=0;j<n;j++){
                if(a[i]<a[j]) break;
                x+=(a[i]-a[j]);
                if(x<=m)y++;
                else break;
            }
            max_num=max(max_num,y);
        }
        cout<<max_num;
    }


	return 0;
}
