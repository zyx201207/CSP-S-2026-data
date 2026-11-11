#include<fstream>
#include<vector>
#include<string>

using namespace std;
ifstream cin("migrate.in");
ofstream cout("migrate.out");
long long A[2000010];
int rn_hou(int n,int starti,int d);
void solve(int n);
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    cin >> T;
    for(int q=0;q<T;q++){
        int n;
        cin >> n;
        solve(n);
    }
    cout << endl;
    cin.close();
    cout.close();
    return 0;
}
int rn_hou(int n,int starti,int d){
    int n_hou=0;
    for(int i=starti;i<n-2;i++){
        if(A[i]+d<A[i+2]&&A[i]+d>=A[i+1])n_hou++;
        else break;
    }
    return n_hou;
}
void solve(int n){
    int d;
    cin >> d;
    for(int i=0;i<n;i++)cin >> A[i];
    int starti=0;
    
    long long sum=0;

    while(starti<n-2){
        int n_qian=1,n_hou=0;
        for(int i=starti;i<n-2;i++){
            if(A[i]+d<A[i+2]&&A[i]+d>=A[i+1]){
                n_qian++;
                continue;
            }
            else if(A[i]+d<A[i+1]){//Ìø²»¹ýÈ¥
                starti=i+1;
                break;
            }
            else if(i+2==n-1){
                starti=n;
                break;
            }
        
            else{
                if(i+3<n){
                    // if(A[i]+d<A[i+3]&&A[i+2]+d>=A[i+3]){
                    if(A[i]+d<A[i+3]&&A[i]+d>=A[i+2]&&A[i+2]+d>=A[i+3]){
                        // i ~ i+3 cun ___OO___
                        // n_hou++;
                        n_hou=1;
                        n_hou+=rn_hou(n,i+3,d);
                        // cout << "i=" << i << endl;
                        // cout << "n_hou=" << n_hou << endl ;
                        sum+=n_hou*n_qian;
                        starti=i+1;
                        break;
                    }
                    else{
                        starti=i+1;
                        break;
                    }

                }
                else{
                    starti=n;
                    break;
                }
                
            }//
            

        }
    }
    cout << sum << endl;
    return;
}
