#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5+5;
int n,m;
vector<int> a;
vector<int> sum(M);

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}

	//for(int i=0;i<n;i++) cout<<a[i];
	
	for(int i=0;i<n;i++){//n局 
		vector<int> b;//初始为空 
		for(int j=i;j<n;j++){//忽略前i-1张卡牌 
			int k=a[j];//当前要插入的 
			
			int f=0;
			bool ff=false;
			for(int mid=0;mid<b.size();mid++){
				if(b[mid]==k){
					f=mid;
					ff=true;
					break;
				}
			}
			if(ff) b.erase(b.begin()+f,b.end());//删除 
			
			b.push_back(k);//插入 
			
		}
		
		
		for(int mid=0;mid<b.size();mid++) sum[b[mid]]++;
		//cout<<endl;
		
		
	}
	
	for(int i=1;i<=m;i++) cout<<sum[i]<<' ';
	
	return 0;
}

