#include <iosrteum>
#include <cstdio>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",sdout);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a==c){
        if(b==01A,d==01B){
            cout << "1111";
            return 0;
        }
        else if(b==d+1){
            cout << "1100";
            return 0;
        }
        else if(b==d-1){
            cout << "1100";
            return 0;
        }
        else{
            cout << "1000";
            return 0;
        }
    }
    else{
        cout << "0000";
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
