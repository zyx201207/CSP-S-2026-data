#include<bits/stdc++.h>
using namespace std;

struct chars{
	int start,end;
	char c;
}itm[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	int nows=1,midpos=-1;
	for(int i=0;i<n;i++){
		int l;
		char ch;
		cin>>l>>ch;
		itm[i].start=nows;
		itm[i].end=nows+l-1;
		itm[i].c=ch;
		nows+=l;
	}
	
	int midn=(nows)/2;
	nows--;
//	cout<<midn<<" "<<nows<<"\n";
	for(int i=0;i<n;i++){
		if(itm[i].start<=midn&&itm[i].end>=midn){
			midpos=i;
			break;
		}
	}
	int l=midpos,r=midpos;
	int cnt=0;
	for(int i=0;i<midn;i++){
//		cout<<"time "<<i<<": ";
		if(itm[l].start>midn-i){
			l--;
//			cout<<"l flow\n"; 
		}
		if(nows%2==0&&itm[r].end<midn+i+1){
			r++;
//			cout<<"dou r flow\n";
		}
		else if(nows%2==1&&itm[r].end<midn+i){
//			cout<<itm[r].end<<"<"<<midn+i<<" sim r flow\n";
			r++;
		}
		if(itm[l].c!=itm[r].c){
			cnt++;
//			cout<<"fnd on pos "<<i<<'\n';
//			cout<<"use "<<l<<' '<<itm[l].c<<" and "<<r<<' '<<itm[r].c<<'\n';
		}
//		cout<<"sertch on "<<midn-i<<" and "<<midn+i<<'\n';
	}
//	for(int i=0;i<n;i++){
//		cout<<itm[i].start<<" "<<itm[i].end<<" "<<itm[i].c<<'\n';
//	}
	cout<<cnt;
	
	return 0;
}//i hate simulation
