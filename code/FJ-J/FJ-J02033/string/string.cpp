#include<bits/stdc++.h>
using namespace std;
long long num_[200005];
long long num[500005];
long long sum_[200005];
long long sum[500005];
long long sum2[500005];
char ch_[200005];
char ch[500005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n,n_;
	cin>>n_;
	num_[0]=0;
	sum_[0]=0;
	for(int i=1;i<=n_;i++){
		cin>>num_[i]>>ch_[i];
		sum_[i]=sum_[i-1]+num_[i];
	}
	vector<long long> nodes;
	for(int i=0;i<=n_;i++){
		nodes.push_back(sum_[i]);
		nodes.push_back(sum_[n_]-sum_[i]);
	}
	sort(nodes.begin(),nodes.end());
	vector<long long> nodes2;
	nodes2.push_back(0);
	for(int i=0;i<nodes.size();i++){
		if(nodes[i]!=nodes2.back()){
			nodes2.push_back(nodes[i]);
		}
	}
	int pp1=1,pp2=1;
	for(int i=1;i<=nodes2.size();i++){
		while(nodes2[i]>sum_[pp1] && pp1<=n_)pp1++;
	    if(nodes2[i]<=sum_[pp1]){
	    	num[pp2]=nodes2[i]-nodes2[i-1];
	    	ch[pp2]=ch_[pp1];
	    	pp2++;
		}
	}
	n=pp2;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+num[i];
	}
	long long Size=sum[n];
	for(int i=0;i<=n;i++)sum2[i]=Size-sum[i];
	long long ans=Size/2;
	int p1=1,p2=n;
	while(p1<p2){
		long long l1=sum[p1-1]+1,r1=sum[p1];
		long long l2=sum2[p2]+1,r2=sum2[p2-1];
//		cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
		if(ch[p1]!=ch[p2]){
			if(r1<r2)p1++;
			else p2--;
			continue;
		}
        if(p1==p2){
        	ans-=(r1-l1+1+1)/2;
        	break;
		}
		if(l1<=l2 && r2<=r1){//itv1 include itv2
			ans-=(r2-l2+1);
			p2--;
			continue;
		}
		else if(l2<=l1 && r1<=r2){//itv2 include itv1
			ans-=(r1-l1+1);
			p1++;
			continue;
		}
		else if(r2<l1 || r1<l2){//no cover
			if(r2<l1)p2--;
			else if(r1<l2)p1++;
			continue;
		}
		else if((l1<=l2 && r1<=r2) && l2<=r1){// l1 l2 r1 r2;
			ans-=(r1-l2+1);
			p1++;
			continue;
		}
		else if((l2<=l1 && r2<=r1) && r2>=l1){
			ans-=(r2-l1+1);
			p2--;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
