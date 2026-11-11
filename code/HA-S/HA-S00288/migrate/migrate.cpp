

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,ans=0,cd=1;
	cin>>c>>t;
	vector<int> Ans;
	for(int i=0;i<t;i++){
		long long n,d;
		cin>>n>>d;
		vector<long long> N(n+2);
		for(int j=0;j<n;j++){
			cin>>N[j];
		}
		cd=1;
		ans=0;
		for(int j=0;j<n-1;j++){
			if(abs(N[j+1]-N[j])<=d){
				cd+=1;
			}else{
				if(cd>=2*d){
					d=d/(N[1]-N[0]);
					ans+=cd-2*d+1;
					
					//cout<<'o';
					
				}
				cd=1;
			}
			
		}
		if(cd>=2*d){
			d=d/(N[1]-N[0]);
			ans+=cd-2*d+1;
			
			//cout<<'o';
			
		}
		
//		cout<<endl;
//		for(int j=0;j<n;j++){
//			cout<<N[i]<<" ";
//		}
//		cout<<endl;
		
		//cout<<cd<<' ';
		
		//cout<<ans<<'\n';
		Ans.push_back(ans);
	}
	
	for(int i=0;i<t;i++){
		cout<<Ans[i];
		if(i!=t-1) cout<<'\n';
	}
	
	return 0;
}



//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5


//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6












