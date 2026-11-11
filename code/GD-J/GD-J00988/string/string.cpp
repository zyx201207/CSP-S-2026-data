#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#define int long long
using namespace std;

const int maxn=2e5+10;
pair<char,int> blo[maxn];
pair<char,int> left[maxn];
pair<char,int> right[maxn];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	int n;
	cin>>n;
	string str;
	vector<pair<char,int> > left,right;
	int tot=0;
	for(int i=0;i<n;i++){
		int x;
		char ch;
		cin>>x>>ch;
		blo[i].first=ch;
		blo[i].second=x;
		tot+=x;
	}
	int tmpt=0;
	for(int i=0;i<n;i++){
		tmpt+=blo[i].second;
		if(tmpt<=tot/2) left.push_back(blo[i]);
		else if(tmpt-blo[i].second>tot/2) right.push_back(blo[i]);
		else {
			right.push_back(make_pair(blo[i].first,tmpt-tot/2));
			if(blo[i].second-(tmpt-tot/2)!=0)left.push_back(make_pair(blo[i].first,blo[i].second-(tmpt-tot/2)));
			if(tot%2==1) right[right.size()-1].second--;
		}
	}
	int li=0,ri=0;
	int sum=0,curl=0,curr=0;
	reverse(right.begin(),right.end());
	while(li<left.size()){
		if(left[li].second>right[ri].second){
			if(left[li].first!=right[ri].first) sum+=right[ri].second;
			left[li].second-=right[ri].second;
			ri++;
		} 
		else if(left[li].second<right[ri].second) {
			if(left[li].first!=right[ri].first) sum+=left[li].second;
			right[ri].second-=left[li].second;
			li++;
		}
		else {
			if(left[li].first!=right[ri].first) sum+=left[li].second;
			ri++,li++;
		}
	}
	cout<<sum<<endl;
	return 0;
}

