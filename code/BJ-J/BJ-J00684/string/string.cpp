#include<fstream>
#include<string>
using namespace std;
int  main(){
    ifstream fin("string.in");
    ofstream fout("string.out");
    int n,ans=0;
    fin>>n;
    char c[n];
    int num[n];
    for(int i=0;i<n;i++) fin>>num[i]>>c[i];
    int front_i=0,front_more=num[0],behind_i=n-1,behind_more=num[n-1];

    while(front_i!=behind_i){
        if(front_more>behind_more) {
            if(c[front_i]!=c[behind_i]) {
                ans+=behind_more;
            }
            front_more-=behind_more;
            behind_i--;
            behind_more=num[behind_i];
        }
        else if(front_more<behind_more){
            if(c[front_i]!=c[behind_i]) {
                ans+=front_more;
            }
            behind_more-=front_more;
            front_i++;
            front_more=num[front_i];
        }
        else {
            if(c[front_i]!=c[behind_i]) {
                ans+=front_more;
            }
            front_i++;
            if(front_i==behind_i) {
                break;
            }
            behind_i--;
            behind_more=num[behind_i];
            front_more=num[front_i];
        }
    }
    fout<<ans;
    return 0;
}
