#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m;
int a[5000],b[5000][5000];
int main(){
	freopen ("crystal.in","r",stdin);
	freopen ("crystal.out","w",stdout);
	cin >> n>> m;
	for (int i = 1 ; i <= n ; i ++){
		cin >>a [i];
	}
	
	for(int i = 1;i <=n ;i ++){
		int k = 0;
		for(int j = 1;j <= n;j ++){
			if(i != j){
				k++;
			b[i][k] = abs (a[i] - a[j]);
	    //cout<<b[i][k]<<' ';	
			}
		}
	//	cout<<endl;
	}	
	int ct = 0,s = 0;
	int ans = 0,cont = 0;
	for (int u = 1;u <= n;u++){
		for (int i = 1;i <= n-1;i++){
			int f = 0;
				for (int j = i;j <= n-1;j ++){
		        if(f < m){
		            f += b[u][j];
			        ans++; cont++;
		        }	
		    else if (f == m){
		    	s = b[u][j];
		    	ct = cont;
	             break;
			}
			else{
			ans = 0;
			cont = 0;
			    }	
		    }	
	    }
	}
		int anser = 0, p = 0;
		s = s + a[ct];
		for (int i = 1;i <= n; i++){
			if (a[i] == s)
			anser++;
		}
			cout << anser + ans;
	return 0;
}
