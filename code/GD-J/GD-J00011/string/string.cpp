#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long l,r;
	char c;
}a[200005];
vector<node>fr;
vector<node>ba;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	long long sum=1;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int i=1;i<=x;i++){
			s+=c;
		}
		a[i].l=sum;
		a[i].r=sum+x-1;
		sum=sum+x;
		a[i].c=c;
	}
	int len=s.size();
	int ans=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len+1-i]){
			ans++;
		}
	}
	cout<<ans;
//	sum=sum-1;
//	long long mi=(sum+1)/2;
//	for(int i=1;i<=n;i++){
//		if(a[i].l<=mi&&mi<=a[i].r){
//			
//				for(int j=1;j<i;j++){
//					fr.push_back({a[j].l,a[j].r,a[j].c});
//				}
//				int be=1;
//				for(int j=n;j>=i+1;j--){
//					ba.push_back({be,be+a[j].r-a[j].l,a[j].c});
//					be=be+a[j].r-a[j].l+1;
//				}
//				if(mi>(a[i].r+a[i].l)/2){
//					fr.push_back({a[i-1].r+1,a[i-1].r+(mi+mi-a[i].l-a[i].r),a[i].c});
//				}else{
//					ba.push_back({be,be+a[i].r-mi-mi+a[i].l-1,a[i].c});
//				}
//				break;
//			
//		}
//	}
//	
//	
//	long long ans=0;
//	int i=0,j=0;
//	while(true){
//		if(ba[j].r>=fr[i].r){
//			if(fr[i].l<ba[j].l){
//				ans+=fr[i].r-ba[j].l+1;
//			}else{
//				ans+=fr[i].r-fr[i].l+1;
//			}
//		}else{
//			if(fr[i].l<ba[j].l){
//				ans+=ba[j].r-ba[j].l+1;
//			}else{
//				ans+=ba[j].r-fr[i].l;
//			}
//		}
//		
//		if(ba[j].r<fr[i].r){
//			j++;
//		}
//		else if(fr[i].r<ba[j].r){
//			i++;
//		}
//		if((i>=fr.size()-1) && (j>=ba.size()-1))break;
//		cout<<i<<" "<<j<<" "<<ans<<endl;
//	}
//	
//	cout<<ans<<endl;
//	for(int i=0;i<fr.size();i++){
//		cout<<fr[i].l<<" "<<fr[i].r<<" "<<fr[i].c<<endl;
//	}
//	cout<<endl;
//	
//	for(int i=0;i<ba.size();i++){
//		cout<<ba[i].l<<" "<<ba[i].r<<" "<<ba[i].c<<endl;
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
2 a
2 b
1 c
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
